# $NetBSD: Makefile,v 1.3 2003/01/31 11:07:05 shell Exp $
#

DISTNAME=	XML-Simple-2.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xsi
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Easy Perl API to read/write XML

DEPENDS+=       p5-XML-SAX-[0-9]*:../../textproc/p5-XML-SAX
DEPENDS+=       p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=       p5-Storable-[0-9]*:../../devel/p5-Storable

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
