# $NetBSD: Makefile,v 1.9 2005/04/11 21:48:01 tv Exp $
#

DISTNAME=	WWW-Amazon-Wishlist-0.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5waw
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cpan.org/modules/by-module/WWW/WWW-Amazon-Wishlist-0.65.readme
COMMENT=	Perl5 module to get details from your Amazon wishlist

DEPENDS+=	p5-libwww-*:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/WWW/Amazon/Wishlist/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
