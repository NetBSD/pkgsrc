# $NetBSD: Makefile,v 1.31 2018/08/22 09:47:53 wiz Exp $

DISTNAME=		Template-Generate-0.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		18
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~autrijus/Template-Generate/
COMMENT=		Perl5 module for generating TT2 templates from TT2-rendered documents
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

DEPENDS+=	p5-Apache-DBI>=0.87:../../databases/p5-Apache-DBI
DEPENDS+=	p5-DBI>=1.18:../../databases/p5-DBI
DEPENDS+=	p5-Date-Calc>=4.3:../../devel/p5-Date-Calc
DEPENDS+=	p5-GD>=1.32:../../graphics/p5-GD
DEPENDS+=	p5-GD-Graph3d>=0.55:../../graphics/p5-GD-Graph3d
DEPENDS+=	p5-GDGraph>=1.33:../../graphics/p5-GDGraph
DEPENDS+=	p5-Pod-POM-[0-9]*:../../textproc/p5-Pod-POM
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../textproc/p5-Text-Autoformat
DEPENDS+=	p5-XML-DOM>=1.43:../../textproc/p5-XML-DOM
DEPENDS+=	p5-XML-Parser>=2.30:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-RSS>=0.9:../../textproc/p5-XML-RSS
DEPENDS+=	p5-XML-XPath>=1.08:../../textproc/p5-XML-XPath

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Template/Generate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
