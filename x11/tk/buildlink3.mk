# $NetBSD: buildlink3.mk,v 1.25 2012/03/05 13:36:37 obache Exp $

BUILDLINK_TREE+=	tk

.if !defined(TK_BUILDLINK3_MK)
TK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk+=	tk>=8.4.12nb1
BUILDLINK_ABI_DEPENDS.tk+=	tk>=8.4.12nb1
BUILDLINK_PKGSRCDIR.tk?=	../../x11/tk

BUILDLINK_FILES.tk+=	bin/wish*
#
# Make "-ltk" and "-ltk8.4" resolve into "-ltk84", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk:tk84
BUILDLINK_TRANSFORM+=	l:tk8.4:tk84

TKCONFIG_SH?=	${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh

_TOOLS_USE_PKGSRC.wish=	yes

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # TK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk
