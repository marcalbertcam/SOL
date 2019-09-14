// Linux Operative Systems
// Final Project
// CPU usage indicator with 8-LEDs
// Marcos A. Camarena R.
// September 2019

/*based on:
https://michaeljomori.com/2019/05/11/raspberry-pi-3-b-cpu-usage-driver-loadable-kernel-module-lkm/
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>

#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>

#include <linux/syscalls.h>
#include <linux/fcntl.h>

MODULE_LICENSE("GPL");

#define L1 18
#define L2 23
#define L3 27
#define L4 16
#define L5 17
#define L6 26
#define L7 13
#define L8 22

MODULE_LICENSE("GPL");
//int num_leds;
long num_leds;
int i;
int leds[10];
struct file *fp;
// Create variables
struct file *f;
char buf[128];
mm_segment_t fs;
int i;
int result;

static ssize_t set_period_callback(struct device* dev,
    struct device_attribute* attr,
    const char* buf,
    size_t count)
{
    long period_value = 0;
    
    if (kstrtol(buf, 10, &period_value) < 0)
        return -EINVAL;
    if (period_value < 10)	//Safety check
    	return - EINVAL;
    num_leds = period_value / 10;
    for(i = 1; i < num_leds + 1; i++){
      gpio_set_value(leds[i], true);
    }
    for(i = num_leds + 1; i < 10; i ++){
      gpio_set_value(leds[i], false);
    }
    return count;
}

static DEVICE_ATTR(period, S_IRWXU | S_IRWXG, NULL, set_period_callback);

static struct class *s_pDeviceClass;
static struct device *s_pDeviceObject;

void file_close(struct file *file) 
{
    filp_close(file, NULL);
}

static int __init pix_init(void){
  //https://www.fsl.cs.sunysb.edu/kernel-api/re244.html
  leds[1] = 18;
  leds[2] = 23;
  leds[3] = 27;
  leds[4] = 16;
  leds[5] = 17;
  leds[6] = 26;
  leds[7] = 13;
  leds[8] = 22;
  
  printk(KERN_INFO "Initialized");

  gpio_request(leds[1], "L1");
  gpio_direction_output(leds[1], true);
  gpio_set_value(leds[1], false);

  gpio_request(leds[2], "L2");
  gpio_direction_output(leds[2], true);
  gpio_set_value(leds[2], false);

  gpio_request(leds[3], "L3");
  gpio_direction_output(leds[3], true);
  gpio_set_value(leds[3], false);

  gpio_request(leds[4], "L4");
  gpio_direction_output(leds[4], true);
  gpio_set_value(leds[4], false);

  gpio_request(leds[5], "L5");
  gpio_direction_output(leds[5], true);
  gpio_set_value(leds[5], false);

  gpio_request(leds[6], "L6");
  gpio_direction_output(leds[6], true);
  gpio_set_value(leds[6], false);

  gpio_request(leds[7], "L7");
  gpio_direction_output(leds[7], true);
  gpio_set_value(leds[7], false);

  gpio_request(leds[8], "L8");
  gpio_direction_output(leds[8], true);
  gpio_set_value(leds[8], false);
 
  printk(KERN_INFO "Finished Initalization");
  
  s_pDeviceClass = class_create(THIS_MODULE, "LedBlink");
  BUG_ON(IS_ERR(s_pDeviceClass));

  s_pDeviceObject = device_create(s_pDeviceClass, NULL, 0, NULL, "LedBlink");
  BUG_ON(IS_ERR(s_pDeviceObject));

  result = device_create_file(s_pDeviceObject, &dev_attr_period);
  BUG_ON(result < 0);

  return 0;
}

static void __exit pix_exit(void){
  printk(KERN_INFO "Removing module");

  gpio_free(leds[1]);
  gpio_free(leds[2]);
  gpio_free(leds[3]);
  gpio_free(leds[4]);
  gpio_free(leds[5]);
  gpio_free(leds[6]);
  gpio_free(leds[7]);
  gpio_free(leds[8]);

  device_remove_file(s_pDeviceObject, &dev_attr_period);
  device_destroy(s_pDeviceClass, 0);
  class_destroy(s_pDeviceClass);

  printk(KERN_INFO "Finished removing");
}

module_init(pix_init);
module_exit(pix_exit);