# $NetBSD: Makefile,v 1.3 2000/08/27 07:11:24 jlam Exp $
#

DISTNAME=	checkbot-1.60
CATEGORIES=	www net perl5
MASTER_SITES=	http://www.xs4all.nl/~graaff/checkbot/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~graaff/checkbot/

DEPENDS+= 	p5-MailTools-*:../../mail/p5-MailTools
DEPENDS+= 	p5-Net-*:../../net/p5-Net
DEPENDS+= 	p5-URI-*:../../www/p5-URI
DEPENDS+= 	p5-libwww-*:../../www/p5-libwww

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/checkbot/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
