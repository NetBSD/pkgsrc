# $NetBSD: Makefile,v 1.6 2003/07/17 22:54:41 grant Exp $

DISTNAME=	XML-SAX-0.12
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=	
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl interface to the SAX2 XML Parser

DEPENDS+=	p5-XML-NamespaceSupport>=0.03:../../textproc/p5-XML-NamespaceSupport
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/SAX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
