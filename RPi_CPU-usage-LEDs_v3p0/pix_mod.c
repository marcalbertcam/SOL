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

#define A1 18 //Pin12
#define A2 23 //Pin16
#define A3 27 //Pin13 
#define A4 16 //Pin36
#define A5 17 //Pin11
#define A6 26 //Pin37
#define A7 13 //Pin33
#define A8 22 //Pin15

MODULE_LICENSE("GPL");

static int __init pix_init(void){
  printk(KERN_INFO "PIX: starting...");
  // stuff to do
  gpio_request(A1, "A1");
  gpio_direction_output(A1, true);
  gpio_set_value(A1, true);
  
  gpio_request(A2, "A2");
  gpio_direction_output(A2, true);
  gpio_set_value(A2, true);
  
  gpio_request(A3, "A3");
  gpio_direction_output(A3, true);
  gpio_set_value(A3, true);
  
  gpio_request(A4, "A4");
  gpio_direction_output(A4, true);
  gpio_set_value(A4, true);
  
  gpio_request(A5, "A5");
  gpio_direction_output(A5, true);
  gpio_set_value(A5, true);
  
  gpio_request(A6, "A6");
  gpio_direction_output(A6, true);
  gpio_set_value(A6, true);
  
  gpio_request(A7, "A7");
  gpio_direction_output(A7, true);
  gpio_set_value(A7, true);
  
  gpio_request(A8, "A8");
  gpio_direction_output(A8, true);
  gpio_set_value(A8, false); 
              
  printk(KERN_INFO "PIX: staring done.");
  return 0;
}

static void __exit pix_exit(void){
  printk(KERN_INFO "PIX: stopping...");
  // stuff to do
  gpio_free(A1);
  gpio_free(A2);
  gpio_free(A3);
  gpio_free(A4);
  gpio_free(A5);
  gpio_free(A6);
  gpio_free(A7);
  gpio_free(A8);
  
  printk(KERN_INFO "PIX: stopping done.");
}

module_init(pix_init);
module_exit(pix_exit);
