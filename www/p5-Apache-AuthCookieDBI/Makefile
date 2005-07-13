# $NetBSD: Makefile,v 1.6 2005/07/13 18:01:45 jlam Exp $
#

DISTNAME=	Apache-AuthCookieDBI-1.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~cromis/Apache-AuthCookieDBI-1.19/
COMMENT=	Perl5 module AuthCookie backed by a DBI database

DEPENDS+=	p5-Apache-AuthCookie>=3.05:../../www/p5-Apache-AuthCookie

PERL5_PACKLIST=		auto/Apache/AuthCookieDBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
