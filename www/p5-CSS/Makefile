# $NetBSD: Makefile,v 1.7 2011/11/07 15:13:15 hiramatsu Exp $
#

DISTNAME=	CSS-1.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CSS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CSS/
COMMENT=	Object oriented access to Cascading Style Sheets
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Parse-RecDescent>=1.0:../../devel/p5-Parse-RecDescent

PERL5_PACKLIST=		auto/CSS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
