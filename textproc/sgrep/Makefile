# $NetBSD: Makefile,v 1.1.1.1 2010/04/14 20:19:28 wiz Exp $
#

DISTNAME=	sgrep-1.94a
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.helsinki.fi/pub/Software/Local/Sgrep/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.helsinki.fi/u/jjaakkol/sgrep.html
COMMENT=	Tool for searching and indexing text, SGML,XML and HTML files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
# only used for example files
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/examples/sgrep

INSTALLATION_DIRS+=	share/doc/sgrep

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/sgrep

.include "../../mk/bsd.pkg.mk"
