# $NetBSD: Makefile,v 1.27 2008/10/19 19:19:17 he Exp $
#

DISTNAME=	Template-Toolkit-2.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5tto
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.template-toolkit.org/
COMMENT=	Perl5 text template and dynamic web page integration toolkit

DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig

PERL5_PACKLIST=	auto/Template/.packlist

MAKE_PARAMS=	TT_PREFIX=${PREFIX}/share/tt2
MAKE_PARAMS+=	TT_LATEX=y
MAKE_PARAMS+=	TT_LATEX_PATH=${LOCALBASE}/bin/latex
MAKE_PARAMS+=	TT_PDFLATEX_PATH=${LOCALBASE}/bin/pdflatex
MAKE_PARAMS+=	TT_DVIPS_PATH=${LOCALBASE}/bin/dvips
MAKE_PARAMS+=	TT_ACCEPT=y

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
