# $NetBSD: Makefile,v 1.7 2002/10/27 20:49:01 seb Exp $
#

DISTNAME=	XML-XQL-0.67
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xxq
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module to perform XQL queries on XML object trees

DEPENDS+=	p5-XML-DOM-[0-9]*:../p5-XML-DOM
DEPENDS+=	p5-XML-Parser-2.*:../p5-XML-Parser
DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip

CONFLICTS+=	p5-libxml-enno-[0-9]*

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/XQL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
