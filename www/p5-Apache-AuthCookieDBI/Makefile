# $NetBSD: Makefile,v 1.1.1.1 2004/11/05 19:24:22 he Exp $
#

DISTNAME=	Apache-AuthCookieDBI-1.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tegk-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~cromis/Apache-AuthCookieDBI-1.19/
COMMENT=	Perl5 module AuthCookie backed by a DBI database

DEPENDS+=	p5-Apache-AuthCookie>=3.05:../../www/p5-Apache-AuthCookie

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/AuthCookieDBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
