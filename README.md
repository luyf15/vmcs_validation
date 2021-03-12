# vmcs_validation

Based on the project kvm-hello-world

# A minimal KVM example

kvm-hello-world is a very simple example program to demonstrate the
use of the KVM API provided by the Linux kernel.  It acts as a very
simple VM host, and runs a trivial program in a VM.  I tested it on
Intel processors with the VMX hardware virtualization extensions.  It
*might* work on AMD processors with AMD-V, but that hasn't been
tested.

The code is straightforward.  It:

* Opens `/dev/kvm` and checks the version.
* Makes a `KVM_CREATE_VM` call to creates a VM.
* Uses mmap to allocate some memory for the VM.
* Makes a `KVM_CREATE_VCPU` call to creates a VCPU within the VM, and
  mmaps its control area.
* Sets the FLAGS and CS:IP registers of the VCPU.
* Copies a few bytes of code into the VM memory.
* Makes a `KVM_RUN` call to execute the VCPU.
* Checks that the VCPU execution had the expected result.

##Notes

There's another project that is much more approachable:
[kvmtool](https://github.com/kvmtool/kvmtool). Like qemu, kvmtool does
full-system emulation.  unlike qemu, it is deliberately minimal,
emulating just a few devices.  But while kvmtool is impressive
demonstration of how simple and clean a KVM-based full-system emulator
can be, it's still far more than a bare-bones example.

So, as no such example seems to exist, I wrote one by studying api.txt
and the kvmtool sources.  (Update: When I wrote this, I had overlooked
https://github.com/soulxu/kvmsample).
