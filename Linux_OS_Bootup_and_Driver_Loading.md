# Linux OS Bootup and Driver Loading

**Link**: [https://www.quora.com/I-understand-that-a-CPU-has-protection-rings-How-does-the-operating-system-initialize-these-protection-rings-How-are-ring-0-and-ring-3-defined](https://www.quora.com/I-understand-that-a-CPU-has-protection-rings-How-does-the-operating-system-initialize-these-protection-rings-How-are-ring-0-and-ring-3-defined)

---

## Boot Process Steps
Both the **boot-loader** and the **operating system (OS)** code are stored in the **SSD/HDD**.  
1. Powers On  
2. CPU executes instructions from **ROM (BIOS code)** to check if all the Hardware is in Good Condition & boots the overall power of the System & other Basic checks are done. This is called POST (**Power-On Self-Test**)
3. BIOS then tells the CPU to `Load` the `Boot-loader` from **SSD to RAM**, then CPU executes code of Boot-loader. The screen we see that allows selecting between **multiple operating systems** (in `Dual Boot` systems) is actually the **boot-loader menu**.
4. The boot-loader instructs the CPU to **load the OS kernel into RAM**.  
5. Linux Kernel needs to know which Hardwares are available.  
6. During Boot-loader execution, Boot-loader Passes `dtb (Device Tree Blob)` to Linux Kernel… it’s like Boot-loader is calling a “METHOD” of Linux kernel and passing the “dtb” as PARAMETERS of that “method” to Linux Kernel  
7. That’s how Linux Kernel get the “device driver” information during bootup

---

## How the Linux Kernel Detects Hardware

- The **Linux kernel** needs to know which hardware components are available.
- During the boot-loader execution, the boot-loader passes a **Device Tree Blob (DTB)** to the Linux kernel.
- You can think of this process as the **boot-loader calling a "method" of the Linux kernel**, passing the **DTB** as a **parameter**.
- This **DTB** provides the kernel with the necessary **device driver and hardware configuration information** during boot-up.

---

### Summary Analogy

> Boot-loader → calls Linux Kernel (like a function) → passes DTB as parameter  
> Kernel → uses DTB → knows about all available hardware and corresponding drivers