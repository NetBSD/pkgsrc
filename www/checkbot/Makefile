# $NetBSD: Makefile,v 1.14 2002/10/31 08:36:32 seb Exp $
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

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/checkbot/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
