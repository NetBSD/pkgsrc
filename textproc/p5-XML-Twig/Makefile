# $NetBSD: Makefile,v 1.3 2004/04/23 20:39:54 minskim Exp $
#

DISTNAME=	XML-Twig-3.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xtw
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xmltwig.com/
COMMENT=	Efficient XML document interface

DEPENDS+=	p5-WeakRef>=0.01:../../devel/p5-WeakRef
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser
DEPENDS+=	p5-File-Temp>=0.12:../../devel/p5-File-Temp

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Twig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
