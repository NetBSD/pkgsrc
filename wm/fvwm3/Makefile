# $NetBSD: Makefile,v 1.2 2020/11/05 09:09:17 ryoon Exp $

DISTNAME=	fvwm3-1.0.0
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=fvwmorg/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fvwmorg/fvwm3
COMMENT=	Multiple large virtual desktop window manager
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config perl:run
USE_TOOLS+=	msgfmt msgmerge xgettext

# xsltproc
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

# otherwise we get installed scripts that point to the tools directory.
CONFIGURE_ENV+=	ac_cv_path_PYTHON=${PYTHONBIN}
CONFIGURE_ENV+=	ac_cv_path_PERL=${PERL5}

CONFIGURE_ARGS+=	--enable-mandoc

# wants python3
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../databases/mongo-c-driver/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
