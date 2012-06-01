#
# Thunk.s: A simple thunk to call through to another function at an
# arbitrary address.
#
# When we are called, the stack frame looks like this:
#
# ... arg2 arg1 arg0 fn-to-call ret-addr
#
# We pull out 'fn-to-call', and put 'ret-addr' back on the stack,
# to create a stack frame as the callee expects to see it:
#
# ... arg2 arg1 arg0 ret-addr
#
# We then jump directly to 'fn-to-call', and when that function
# finishes we return directly to the original invoker of our thunk.
#
# This is ok, since stdcall defines the stack as 'callee clears', and
# the original caller doesn't care that we've removed an item from the
# stack. We don't need to fix it up afterwards.

        .text

# The stdcall convention includes putting the parameter list size in
# the symbol name, in order to ensure that the amount cleared by the
# callee matches up with the amount put on the stack by the caller.

# In C++, we can get around this by declaring the symbol 'cdecl', but
# to interface with GHC, it looks like we just have to go with the
# naming convention.

# So, we create a whole bunch of symbol names, and have them all point
# to the same function!

        .global _thunk@0
        .global _thunk@4
        .global _thunk@8
        .global _thunk@12
        .global _thunk@16
        .global _thunk@20
        .global _thunk@24
        .global _thunk@28
        .global _thunk@32
        .global _thunk@36
        .global _thunk@40
        .global _thunk@44
        .global _thunk@48
        .global _thunk@52
        .global _thunk@56
        .global _thunk@60
        .global _thunk@64
        .global _thunk@68
        .global _thunk@72
        .global _thunk@76
        .global _thunk@80
        .global _thunk@84
        .global _thunk@88
        .global _thunk@92
        .global _thunk@96
        .global _thunk@100
        .global _thunk@104
        .global _thunk@108
        .global _thunk@112
        .global _thunk@116
        .global _thunk@120
        .global _thunk@124
        .global _thunk@128

_thunk@0:
_thunk@4:
_thunk@8:
_thunk@12:
_thunk@16:
_thunk@20:
_thunk@24:
_thunk@28:
_thunk@32:
_thunk@36:
_thunk@40:
_thunk@44:
_thunk@48:
_thunk@52:
_thunk@56:
_thunk@60:
_thunk@64:
_thunk@68:
_thunk@72:
_thunk@76:
_thunk@80:
_thunk@84:
_thunk@88:
_thunk@92:
_thunk@96:
_thunk@100:
_thunk@104:
_thunk@108:
_thunk@112:
_thunk@116:
_thunk@120:
_thunk@124:
_thunk@128:
        popl %eax       # Return address now in EAX
        popl %edx       # Function to call now in EDX
        pushl %eax      # Put the return address back on the stack...
        jmp *%edx       # And jump (not call) to EDX
                        # Never gets here!

	.end
