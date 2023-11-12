# $NetBSD: buildlink3.mk,v 1.8 2023/11/12 13:24:31 wiz Exp $

BUILDLINK_TREE+=	tk

.if !defined(TK_BUILDLINK3_MK)
TK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk+=	tk>=8.5.7<8.6
BUILDLINK_ABI_DEPENDS.tk+=	tk>=8.5.19nb4
BUILDLINK_PKGSRCDIR.tk?=	../../x11/tk85

BUILDLINK_FILES.tk+=	bin/wish*
#
# Make "-ltk" and "-ltk8.5" resolve into "-ltk85", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tk:tk85
BUILDLINK_TRANSFORM+=	l:tk8.5:tk85

TKCONFIG_SH?=	${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh

_TOOLS_USE_PKGSRC.wish=	yes

WISH=			${LOCALBASE}/bin/wish

pkgbase := tk
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.tk:Mxft2)
.  include "../../x11/libXft/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
.  include "../../x11/libX11/buildlink3.mk"
.endif
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # TK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk
