# $NetBSD: Makefile,v 1.13 2007/02/27 13:46:32 wiz Exp $
#

DISTNAME=	WWW-Amazon-Wishlist-1.4
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5waw
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WWW-Amazon-Wishlist/
COMMENT=	Perl5 module to get details from your Amazon wishlist

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Template-Extract-[0-9]*:../../www/p5-Template-Extract

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/WWW/Amazon/Wishlist/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
