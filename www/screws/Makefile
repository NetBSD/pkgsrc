# $NetBSD: Makefile,v 1.4 2004/12/28 02:47:50 reed Exp $
#

DISTNAME=	screws-0.54
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.nopcode.org/prj/screws/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.nopcode.org/?t=screws
COMMENT=	SCRipt Enhaced Web Server

USE_PERL5=	YES
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES

PKG_USERS=	screws
PKG_GROUPS=	www

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/default.conf ${PKG_SYSCONFDIR}/screws.conf
FILESDIR=	${WRKSRC}/src/Utils/files

RCD_SCRIPTS=	screws

.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
