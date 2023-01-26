#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xf704969, "module_layout" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x85bd1608, "__request_region" },
	{ 0xd731cdd9, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x72f94297, "register_candev" },
	{ 0x96edc2f5, "pci_free_irq_vectors" },
	{ 0x95d9e1d1, "pci_write_config_word" },
	{ 0x349cba85, "strchr" },
	{ 0x5d053422, "single_open" },
	{ 0x77358855, "iomem_resource" },
	{ 0x754d539c, "strlen" },
	{ 0xe9c2ad91, "dma_set_mask" },
	{ 0x359f0950, "single_release" },
	{ 0x548e31a0, "usb_reset_endpoint" },
	{ 0x8de7b894, "pci_disable_device" },
	{ 0x3c6f3827, "i2c_transfer" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xd78b86c9, "seq_printf" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xae9b3820, "usb_kill_urb" },
	{ 0xdaef3116, "remove_proc_entry" },
	{ 0x82e7bb9c, "device_destroy" },
	{ 0x289828cc, "__register_chrdev" },
	{ 0xb14ce014, "driver_for_each_device" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xfbc3773, "pci_release_regions" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x659ccd2f, "dma_free_attrs" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xbc3e07db, "device_create_with_groups" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xbe503d2d, "seq_read" },
	{ 0x4c55f5ef, "pv_ops" },
	{ 0x1f87d038, "dma_set_coherent_mask" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xe49ac3e, "can_bus_off" },
	{ 0x71ac5e55, "netif_rx" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x2fb02a73, "dma_get_required_mask" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xdce9f68d, "param_ops_charp" },
	{ 0x303004cd, "pci_set_master" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xf1ecb4f8, "pci_alloc_irq_vectors_affinity" },
	{ 0x8193f9be, "_dev_warn" },
	{ 0xfb578fc5, "memset" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0xdb4ebb88, "close_candev" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0x9898d6aa, "netif_tx_wake_queue" },
	{ 0x6535b752, "pci_iounmap" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x18554f24, "current_task" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0xb7f634e0, "usb_deregister" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xfef216eb, "_raw_spin_trylock" },
	{ 0x38af27c0, "sysfs_remove_file_from_group" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x9ec6ca96, "ktime_get_real_ts64" },
	{ 0xcdef5c0e, "class_unregister" },
	{ 0xde80cd09, "ioremap" },
	{ 0x1edb69d6, "ktime_get_raw_ts64" },
	{ 0xfc7c7886, "usb_set_interface" },
	{ 0xfc8b7ff6, "free_netdev" },
	{ 0x9166fada, "strncpy" },
	{ 0xb6862311, "usb_control_msg" },
	{ 0xb3c9b55c, "pci_read_config_word" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x78048de3, "dma_alloc_attrs" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xdbd16536, "kfree_skb_reason" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x882a1d87, "alloc_candev_mqs" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xa21071e2, "init_net" },
	{ 0x62c64c68, "__class_register" },
	{ 0x461dee21, "_dev_err" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x7eb2bdfa, "pci_find_capability" },
	{ 0x800473f, "__cond_resched" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x2d91a3b3, "can_change_mtu" },
	{ 0xbe2fa088, "i2c_del_adapter" },
	{ 0x55dde90f, "_dev_info" },
	{ 0x37af9a98, "usb_submit_urb" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xc865cafc, "unregister_candev" },
	{ 0x463cb585, "alloc_can_skb" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6eb9009a, "usb_reset_device" },
	{ 0xfeebe072, "usb_bulk_msg" },
	{ 0x1000e51, "schedule" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x404eb683, "usb_clear_halt" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x8754a2ac, "pci_unregister_driver" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0xffa108c3, "__dev_get_by_name" },
	{ 0xb0bf5c9b, "open_candev" },
	{ 0x7c797b6, "kmem_cache_alloc_trace" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x91519f9b, "param_ops_byte" },
	{ 0xcee60703, "pci_irq_vector" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x3d9d351b, "seq_lseek" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0xe3623b5c, "pci_request_regions" },
	{ 0xa11a85dc, "param_array_ops" },
	{ 0xedc03953, "iounmap" },
	{ 0x76c2092d, "__pci_register_driver" },
	{ 0x8f63b77a, "usb_register_driver" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xd559c565, "alloc_canfd_skb" },
	{ 0x684531d5, "sysfs_add_file_to_group" },
	{ 0x6c91c31c, "i2c_bit_add_bus" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xb0e602eb, "memmove" },
	{ 0xdf6ddad, "pci_iomap" },
	{ 0x3614eaf0, "consume_skb" },
	{ 0x6596238f, "param_ops_ushort" },
	{ 0x84644378, "proc_create" },
	{ 0x8f0f09c8, "usb_get_current_frame_number" },
	{ 0x5e515be6, "ktime_get_ts64" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xe9b2e30d, "pci_enable_device" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xc86187a, "param_ops_ulong" },
	{ 0x51e08620, "param_ops_uint" },
	{ 0x6b6e9230, "usb_free_urb" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x220925f6, "usb_alloc_urb" },
	{ 0xc1514a3b, "free_irq" },
};

MODULE_INFO(depends, "can-dev,i2c-algo-bit");

MODULE_ALIAS("pci:v0000001Cd00000001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000003sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000004sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000005sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000006sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000007sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000008sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000009sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000002sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd0000000Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000010sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000013sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000016sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000017sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd00000019sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000001Cd0000001Asv*sd*bc*sc*i*");
MODULE_ALIAS("usb:v0C72p000Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C72p000Dd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C72p0012d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C72p0011d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C72p0013d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C72p0014d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "BD82EE20A7D1756ED041AFC");
