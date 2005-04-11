# $NetBSD: Makefile,v 1.20 2005/04/11 21:48:01 tv Exp $
#

DISTNAME=	Template-Toolkit-2.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5tto
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.template-toolkit.org/
COMMENT=	Perl5 text template and dynamic web page integration toolkit

DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Template/.packlist

MAKE_PARAMS=	TT_PREFIX=${PREFIX}/share/tt2
MAKE_PARAMS+=	TT_LATEX=y
MAKE_PARAMS+=	TT_LATEX_PATH=${LOCALBASE}/bin/latex
MAKE_PARAMS+=	TT_PDFLATEX_PATH=${LOCALBASE}/bin/pdflatex
MAKE_PARAMS+=	TT_DVIPS_PATH=${LOCALBASE}/bin/dvips
MAKE_PARAMS+=	TT_ACCEPT=y

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
