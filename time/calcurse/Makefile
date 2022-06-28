# $NetBSD: Makefile,v 1.1 2022/06/28 12:32:56 pin Exp $

DISTNAME=	calcurse-4.8.0
CATEGORIES=	time
MASTER_SITES=	http://calcurse.org/files/

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://calcurse.org/
COMMENT=	Text based calendar and scheduling application
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2

GNU_CONFIGURE=	yes

USE_TOOLS+=		gmake intltool pkg-config
USE_TOOLS+=		msgfmt msgmerge xgettext

USE_CURSES=	getmouse wide
FAKE_NCURSES=	yes

REPLACE_PYTHON+=	contrib/caldav/calcurse-caldav
REPLACE_PYTHON+=	contrib/vdir/calcurse-vdir

INSTALLATION_DIRS+=	share/examples/calcurse

post-install:
.for f in config.sample
	${INSTALL_DATA} ${WRKSRC}/contrib/caldav/${f} 						\
	${DESTDIR}${PREFIX}/share/examples/calcurse/caldav.config.sample
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
