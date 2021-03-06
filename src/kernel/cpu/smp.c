#include <cpu/smp.h>
#include <intr/lapic.h>
#include <boot/stivale2.h>
#include <mm/pmm.h>
#include <log.h>

/* 
 * smp_init
 * initializes other processors 
 * @param handover : bootloader handover
 */
void smp_init(struct stivale2_struct* handover) {
    struct stivale2_struct_tag_smp* smp_info = (struct stivale2_struct_tag_smp*) stivale2_get_tag(handover, STIVALE2_STRUCT_TAG_SMP_ID);
    if (smp_info == NULL)
        panic("[smp_init] smp struct from bootloader could not be found\n");

    for (uint64_t i = 0; i < smp_info->cpu_count; i++) {
        struct stivale2_smp_info* proc = &smp_info->smp_info[i];

        if (proc->lapic_id != smp_info->bsp_lapic_id) {
            proc->target_stack = (uint64_t) pmm_alloc(PMM_ZONE_NORMAL, 1);
            proc->goto_address = (uint64_t) &smp_ap_entry;
        }
    }
}

/* 
 * smp_ap_entry
 * when processors boot up, they will enter smp_ap_entry
 */
void smp_ap_entry(void) {
    log("[smp_ap_entry] enabling processor %u ...\n", lapic_id());

    // initialize gdt
    // initialize idt (???)
    // map kheap
    // lapic_enable();

    log("[smp_ap_entry] welcome to the club, processor %u!\n", lapic_id());

    for (;;) {
        hlt();
    }
}