.if !defined(PICOM_HACKS_MK)
PICOM_HACKS_MK=	defined

### [Sat Jan 11 23:38:59 JST 2020 : pho]
### The predefined CPP macro __STDC_NO_THREADS__ is expected to be
### defined by *libc* which doesn't support C11 threads... What? Then
### what about libc which doesn't even know what C11 threads are?
###
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-8].*-*)
PKG_HACKS+=	c11-no-threads
CPPFLAGS+=	-D__STDC_NO_THREADS__
.endif

.endif  # PICOM_HACKS_MK
