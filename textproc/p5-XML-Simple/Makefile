# $NetBSD: Makefile,v 1.10 2005/02/19 18:46:39 wiz Exp $
#

DISTNAME=	XML-Simple-2.14
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xsi
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Simple/
COMMENT=	Easy Perl API to read/write XML

DEPENDS+=       p5-XML-SAX-[0-9]*:../../textproc/p5-XML-SAX
DEPENDS+=       p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=       p5-XML-NamespaceSupport-[0-9]*:../../textproc/p5-XML-NamespaceSupport
DEPENDS+=       p5-Storable-[0-9]*:../../devel/p5-Storable
DEPENDS+=       p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
