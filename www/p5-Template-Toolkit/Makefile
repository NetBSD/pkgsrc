# $NetBSD: Makefile,v 1.29 2009/05/18 22:16:14 abs Exp $
#

DISTNAME=	Template-Toolkit-2.20
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tto
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.template-toolkit.org/
#HOMEPAGE=	http://search.cpan.org/dist/Template-Toolkit/
COMMENT=	Perl5 text template and dynamic web page integration toolkit

DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig

PERL5_PACKLIST=	auto/Template/.packlist

MAKE_PARAMS=	TT_ACCEPT=y
#MAKE_PARAMS+=	TT_PREFIX=${PREFIX}/share/tt2
#MAKE_PARAMS+=	TT_BUILD_DOCS=y
#MAKE_PARAMS+=	TT_EXAMPLES=y

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
