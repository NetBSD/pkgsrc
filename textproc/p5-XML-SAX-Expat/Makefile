# $NetBSD: Makefile,v 1.2 2003/06/02 01:16:30 jschauma Exp $

DISTNAME=	XML-SAX-Expat-0.35
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=	
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl SAX2 XML driver sitting on top of Expat (XML::Parser)

DEPENDS+=	p5-XML-NamespaceSupport-[0-9]*:../../textproc/p5-XML-NamespaceSupport
DEPENDS+=	p5-XML-SAX-[0-9]*:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/SAX/Expat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
