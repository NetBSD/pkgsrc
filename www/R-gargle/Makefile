# $NetBSD: Makefile,v 1.1 2022/04/23 06:02:59 mef Exp $

R_PKGNAME=	gargle
R_PKGVER=	1.2.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utilities for Working with Google APIs
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-cli>=3.0.0:../../devel/R-cli
DEPENDS+=	R-fs>=1.3.1:../../devel/R-fs
DEPENDS+=	R-glue>=1.3.0:../../devel/R-glue
DEPENDS+=	R-rappdirs>=0.3.3:../../devel/R-rappdirs
DEPENDS+=	R-rlang>=0.4.9:../../devel/R-rlang
DEPENDS+=	R-withr>=2.4.2:../../devel/R-withr
DEPENDS+=	R-rstudioapi>=0.13:../../math/R-rstudioapi
DEPENDS+=	R-jsonlite>=1.8.0:../../textproc/R-jsonlite
DEPENDS+=	R-httr>=1.4.0:../../www/R-httr

# Packages suggested but not available:
#  'aws.ec2metadata', 'aws.signature', 'mockr', 'sodium'

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
