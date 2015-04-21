# $NetBSD: Makefile,v 1.25 2015/04/21 08:56:42 jperkin Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-dict-plugin-0.3.0
EXTRACT_SUFX=	.tar.gz
CATEGORIES=	textproc
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-dict-plugin/0.3/

HOMEPAGE=	http://goodies.xfce.org/projects/applications/xfce4-dict
COMMENT=	Xfce dictionary server plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
