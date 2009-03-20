# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:25:51 joerg Exp $

BUILDLINK_TREE+=	tk

.if !defined(TK_BUILDLINK3_MK)
TK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk+=		tk-8.3.4*
BUILDLINK_ABI_DEPENDS.tk?=	tk>=8.3.4nb2
BUILDLINK_PKGSRCDIR.tk?=	../../x11/tk83

BUILDLINK_FILES.tk=	bin/wish*
#
# Make "-ltk" resolve into "-ltk83", so that we don't need to patch so
# many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk:tk83

TKCONFIG_SH?=	${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh

.include "../../lang/tcl83/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # TK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk
