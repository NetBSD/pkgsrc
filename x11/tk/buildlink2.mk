# $NetBSD: buildlink2.mk,v 1.4 2002/09/21 10:30:58 jlam Exp $

.if !defined(TK_BUILDLINK2_MK)
TK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		tk
BUILDLINK_DEPENDS.tk?=		tk>=8.3.4
BUILDLINK_PKGSRCDIR.tk?=	../../x11/tk

EVAL_PREFIX+=			BUILDLINK_PREFIX.tk=tk
BUILDLINK_PREFIX.tk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tk=		include/tk.h
BUILDLINK_FILES.tk+=		include/tkDecls.h
BUILDLINK_FILES.tk+=		include/tkPlatDecls.h
BUILDLINK_FILES.tk+=		include/tkIntXlibDecls.h
BUILDLINK_FILES.tk+=		include/tk/*/*.h
BUILDLINK_FILES.tk+=		lib/libtk83.*
BUILDLINK_FILES.tk+=		lib/libtkstub83.*

.include "../../lang/tcl/buildlink2.mk"

# Make "-ltk" resolve into "-ltk83", so that we don't need to patch so
# many Makefiles.
#
BUILDLINK_TRANSFORM+=		l:tk:tk83

BUILDLINK_TARGETS+=	tk-buildlink

tk-buildlink: _BUILDLINK_USE

TKCONFIG_SH?=			${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh

.endif	# TK_BUILDLINK2_MK
