# $NetBSD: Makefile,v 1.30 2009/07/07 19:45:49 sno Exp $
#

DISTNAME=	Template-Toolkit-2.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tto
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.template-toolkit.org/
#HOMEPAGE=	http://search.cpan.org/dist/Template-Toolkit/
COMMENT=	Perl5 text template and dynamic web page integration toolkit
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-AppConfig>=1.56:../../devel/p5-AppConfig

PERL5_PACKLIST=	auto/Template/.packlist

MAKE_PARAMS=	TT_ACCEPT=y
#MAKE_PARAMS+=	TT_PREFIX=${PREFIX}/share/tt2
#MAKE_PARAMS+=	TT_BUILD_DOCS=y
#MAKE_PARAMS+=	TT_EXAMPLES=y

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
