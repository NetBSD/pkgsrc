# $NetBSD: Makefile,v 1.1.1.1 2004/04/23 16:09:20 xtraeme Exp $
#

DISTNAME=	screws-0.52
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
CONF_FILES=	${EGDIR}/screws.conf ${PKG_SYSCONFDIR}/screws.conf
FILESDIR=	${WRKSRC}/src/Utils/files

RCD_SCRIPTS=	screws

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
