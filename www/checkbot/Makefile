# $NetBSD: Makefile,v 1.13 2001/12/17 12:01:27 abs Exp $
#

DISTNAME=	checkbot-1.67
CATEGORIES=	www net perl5
MASTER_SITES=	http://degraaff.org/checkbot/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://degraaff.org/checkbot/
COMMENT=	Verify links on a set of HTML pages

DEPENDS+= 	p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+= 	p5-Net-[0-9]*:../../net/p5-Net
DEPENDS+= 	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+= 	p5-libwww-[0-9]*:../../www/p5-libwww

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/checkbot/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
