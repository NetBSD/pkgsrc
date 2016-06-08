# $NetBSD: Makefile,v 1.32 2016/06/08 19:25:17 wiz Exp $
#

DISTNAME=	WWW-Amazon-Wishlist-2.014
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WWW-Amazon-Wishlist/
COMMENT=	Perl5 module to get details from your Amazon wishlist
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-HTML-Tree>=0:../../www/p5-HTML-Tree

PERL5_PACKLIST=		auto/WWW/Amazon/Wishlist/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
