# $NetBSD: Makefile,v 1.1.1.1 2003/08/07 04:10:03 gson Exp $
#

DISTNAME=	XML-Twig-3.10
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

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Twig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
