# $NetBSD: buildlink2.mk,v 1.8 2004/03/08 20:29:43 minskim Exp $

.if !defined(TK_BUILDLINK2_MK)
TK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		tk
BUILDLINK_DEPENDS.tk?=		tk>=8.4.5
BUILDLINK_PKGSRCDIR.tk?=	../../x11/tk

EVAL_PREFIX+=			BUILDLINK_PREFIX.tk=tk
BUILDLINK_PREFIX.tk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tk=		bin/wish*
BUILDLINK_FILES.tk+=		include/tk.h
BUILDLINK_FILES.tk+=		include/tkDecls.h
BUILDLINK_FILES.tk+=		include/tkPlatDecls.h
BUILDLINK_FILES.tk+=		include/tk/*/*.h
BUILDLINK_FILES.tk+=		lib/libtk84.*
BUILDLINK_FILES.tk+=		lib/libtkstub84.*

USE_X11=	YES

.include "../../lang/tcl/buildlink2.mk"

# Make "-ltk" resolve into "-ltk84", so that we don't need to patch so
# many Makefiles.
#
BUILDLINK_TRANSFORM+=		l:tk:tk84

BUILDLINK_TARGETS+=	tk-buildlink

tk-buildlink: _BUILDLINK_USE

TKCONFIG_SH?=			${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh

.endif	# TK_BUILDLINK2_MK
