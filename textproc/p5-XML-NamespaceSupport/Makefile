# $NetBSD: Makefile,v 1.4 2003/06/02 01:16:30 jschauma Exp $

DISTNAME=	XML-NamespaceSupport-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl module to the SAX2 NamespaceSupport class

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/NamespaceSupport/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
