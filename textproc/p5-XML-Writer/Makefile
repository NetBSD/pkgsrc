# $NetBSD: Makefile,v 1.6 2003/06/02 01:16:29 jschauma Exp $
#

DISTNAME=	XML-Writer-0.4
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xwr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl module for writing XML documents

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Writer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
