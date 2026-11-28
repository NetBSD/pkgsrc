# $NetBSD: Makefile,v 1.10 2026/11/28 07:01:07 vins Exp $

DISTNAME=	calcurse-4.9.1
CATEGORIES=	time
MASTER_SITES=	http://calcurse.org/files/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://calcurse.org/
COMMENT=	Text based calendar and scheduling application
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2

GNU_CONFIGURE=	yes

USE_TOOLS+=	gmake intltool pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	contrib/caldav/calcurse-caldav
REPLACE_PYTHON+=	contrib/vdir/calcurse-vdir

BUILDLINK_TRANSFORM+=	rm:-D_POSIX_C_SOURCE=200809L
BUILDLINK_TRANSFORM+=	opt:-std=c99:-std=gnu99	# realpath()

INSTALLATION_DIRS+=	share/examples/calcurse

post-install:
.for f in config.sample
	${INSTALL_DATA} ${WRKSRC}/contrib/caldav/${f} 						\
	${DESTDIR}${PREFIX}/share/examples/calcurse/caldav.config.sample
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
