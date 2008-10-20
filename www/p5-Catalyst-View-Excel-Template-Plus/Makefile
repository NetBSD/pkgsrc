# $NetBSD: Makefile,v 1.1.1.1 2008/10/20 23:12:02 he Exp $

DISTNAME=	Catalyst-View-Excel-Template-Plus-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-Excel-Template-Plus/
COMMENT=	A Catalyst View for Excel::Template::Plus

DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Excel-Template-Plus>=0.03:../../math/p5-Excel-Template-Plus
BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/View/Excel/Template/Plus/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
