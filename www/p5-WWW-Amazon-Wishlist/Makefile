# $NetBSD: Makefile,v 1.16 2009/01/11 21:06:26 he Exp $
#

DISTNAME=	WWW-Amazon-Wishlist-1.601
PKGNAME=	p5-${DISTNAME:C/601/6.1/}
SVR4_PKGNAME=	p5waw
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WWW-Amazon-Wishlist/
COMMENT=	Perl5 module to get details from your Amazon wishlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-HTML-Tree>=0:../../www/p5-HTML-Tree
DEPENDS+=	p5-Template-Extract-[0-9]*:../../www/p5-Template-Extract

PERL5_PACKLIST=		auto/WWW/Amazon/Wishlist/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
