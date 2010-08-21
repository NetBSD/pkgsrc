# $NetBSD: Makefile,v 1.20 2010/08/21 16:36:33 seb Exp $

DISTNAME=	Apache-SSI-2.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5ass
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-SSI/
COMMENT=	Perl5 module to implement Server Side Includes

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-HTML-SimpleParse>=0.06:../../www/p5-HTML-SimpleParse

PERL5_PACKLIST=		auto/Apache/SSI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
