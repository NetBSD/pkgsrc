# $NetBSD: Makefile,v 1.2 2021/06/07 15:37:39 mef Exp $

R_PKGNAME=	sass
R_PKGVER=	0.4.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Syntactically Awesome Style Sheets ('Sass')
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-fs>=1.5.0:../../devel/R-fs
DEPENDS+=	R-rappdirs>=0.3.1:../../devel/R-rappdirs
DEPENDS+=	R-rlang>=0.4.10:../../devel/R-rlang
DEPENDS+=	R-htmltools>=0.5.1:../../textproc/R-htmltools
DEPENDS+=	R-fs-[0-9]*:../../devel/R-fs
DEPENDS+=	R-rappdirs-[0-9]*:../../devel/R-rappdirs
DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
