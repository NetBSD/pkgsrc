# $NetBSD: Makefile,v 1.8 2001/04/24 09:00:26 abs Exp $
#

DISTNAME=	checkbot-1.64
CATEGORIES=	www net perl5
MASTER_SITES=	http://degraaff.org/checkbot/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://degraaff.org/checkbot/
COMMENT=	Verify links on a set of HTML pages

DEPENDS+= 	p5-MailTools-*:../../mail/p5-MailTools
DEPENDS+= 	p5-Net-*:../../net/p5-Net
DEPENDS+= 	p5-URI-*:../../www/p5-URI
DEPENDS+= 	p5-libwww-*:../../www/p5-libwww

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/checkbot/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
