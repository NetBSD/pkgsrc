# $NetBSD: Makefile,v 1.9 2005/01/06 14:25:56 wiz Exp $

DISTNAME=	SVN-Web-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Unstable snapshot of Subversion repository browser

DEPENDS+=	p5-subversion>=0.32.1:../../devel/p5-subversion
DEPENDS+=	p5-Template-Toolkit>=2.10:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-Diff>=0.35:../../textproc/p5-Text-Diff
DEPENDS+=	p5-XML-RSS>=0.97:../../textproc/p5-XML-RSS
DEPENDS+=	p5-YAML>=0.35:../../textproc/p5-YAML
DEPENDS+=	p5-Apache-DBI>=0.87:../../databases/p5-Apache-DBI
DEPENDS+=	p5-DBI>=1.18:../../databases/p5-DBI
DEPENDS+=	p5-Date-Calc>=4.3:../../devel/p5-Date-Calc
DEPENDS+=	p5-GD>=1.32:../../graphics/p5-GD
DEPENDS+=	p5-GDGraph3d>=0.55:../../graphics/p5-GDGraph3d
DEPENDS+=	p5-GDGraph>=1.33:../../graphics/p5-GDGraph
DEPENDS+=	p5-Pod-POM-[0-9]*:../../textproc/p5-Pod-POM
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../textproc/p5-Text-Autoformat
DEPENDS+=	p5-XML-DOM>=1.43:../../textproc/p5-XML-DOM
DEPENDS+=	p5-XML-Parser>=2.30:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-RSS>=0.9:../../textproc/p5-XML-RSS
DEPENDS+=	p5-XML-XPath>=1.08:../../textproc/p5-XML-XPath
DEPENDS+=	teTeX>=1.0.7:../../print/teTeX

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SVN/Web/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
