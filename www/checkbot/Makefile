# $NetBSD: Makefile,v 1.1.1.1 2000/04/06 15:50:30 kim Exp $
#

DISTNAME=	checkbot-1.59
CATEGORIES=	www net perl5
MASTER_SITES=	http://www.xs4all.nl/~graaff/checkbot/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~graaff/checkbot/

DEPENDS+= 	p5-MailTools-*:../../mail/p5-MailTools
DEPENDS+= 	p5-Net-*:../../net/p5-Net
DEPENDS+= 	p5-URI-*:../../www/p5-URI
DEPENDS+= 	p5-libwww-*:../../www/p5-libwww

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
