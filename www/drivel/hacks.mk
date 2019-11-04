# $NetBSD: hacks.mk,v 1.3 2019/11/04 22:09:53 rillig Exp $

.include "../../mk/bsd.prefs.mk"

# NetBSD 1.x does not define types such as fd_set when _XOPEN_SOURCE is
# defined, unless _XOPEN_SOURCE_EXTENDED also is defined
.if ${OPSYS} == "NetBSD"
.  if empty(OS_VERSION:N1.[56]*)
CFLAGS+=	-D_XOPEN_SOURCE_EXTENDED
.  endif
.endif
