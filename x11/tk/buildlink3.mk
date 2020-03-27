# $NetBSD: buildlink3.mk,v 1.38 2020/03/27 02:07:33 joerg Exp $

BUILDLINK_TREE+=	tk

.if !defined(TK_BUILDLINK3_MK)
TK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk+=	tk>=8.5.7
BUILDLINK_ABI_DEPENDS.tk+=	tk>=8.6.8nb1
BUILDLINK_PKGSRCDIR.tk?=	../../x11/tk

BUILDLINK_FILES.tk+=	bin/wish*
#
# Make "-ltk" and "-ltk8.6" resolve into "-ltk86", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk:tk86
BUILDLINK_TRANSFORM+=	l:tk8.6:tk86

TKCONFIG_SH?=	${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh

_TOOLS_USE_PKGSRC.wish=	yes

WISH=			${LOCALBASE}/bin/wish

pkgbase := tk
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.tk:Mxft2)
.  include "../../x11/libXft/buildlink3.mk"
.endif
.if empty(PKG_BUILD_OPTIONS.tk:Maqua)
. include "../../x11/libX11/buildlink3.mk"
. include "../../x11/libXext/buildlink3.mk"
. include "../../x11/libXScrnSaver/buildlink3.mk"
.endif
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # TK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk
