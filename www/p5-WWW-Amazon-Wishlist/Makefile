# $NetBSD: Makefile,v 1.2 2002/10/27 20:48:57 seb Exp $
#

DISTNAME=	WWW-Amazon-Wishlist-0.65
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5waw
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cpan.org/modules/by-module/WWW/WWW-Amazon-Wishlist-0.65.readme
COMMENT=	perl5 module to get details from your Amazon wishlist

DEPENDS+=	p5-libwww-*:../../www/p5-libwww

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/WWW/Amazon/Wishlist/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
