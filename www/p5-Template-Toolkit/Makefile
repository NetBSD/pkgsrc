# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:56 jlam Exp $
#

DISTNAME=	Template-Toolkit-2.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.template-toolkit.org/
COMMENT=	perl5 text template and dynamic web page intergration toolkit

DEPENDS+=	ap-DBI>=0.87:../../www/ap-DBI
DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig
DEPENDS+=	p5-Date-Calc>=4.3:../../devel/p5-Date-Calc
DEPENDS+=	p5-DBI>=1.18:../../databases/p5-DBI
DEPENDS+=	p5-GD>=1.32:../../graphics/p5-GD
DEPENDS+=	p5-GDGraph>=1.33:../../graphics/p5-GDGraph
DEPENDS+=	p5-GDGraph3d>=0.55:../../graphics/p5-GDGraph3d
DEPENDS+=	p5-libxml-enno>=1.04:../../textproc/p5-libxml-enno
DEPENDS+=	p5-Pod-POM-[0-9]*:../../textproc/p5-Pod-POM
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../textproc/p5-Text-Autoformat
DEPENDS+=	p5-XML-Parser>=2.30:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-RSS>=0.9:../../textproc/p5-XML-RSS
DEPENDS+=	p5-XML-XPath>=1.08:../../textproc/p5-XML-XPath
DEPENDS+=	teTeX>=1.0.7:../../print/teTeX

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Template/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
