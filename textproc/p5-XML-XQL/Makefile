# $NetBSD: Makefile,v 1.1.1.1 2001/08/10 12:51:53 mjl Exp $
#

DISTNAME=	XML-XQL-0.66
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module to perform XQL queries on XML object trees

DEPENDS+=	p5-XML-DOM-*:../p5-XML-DOM
DEPENDS+=	p5-XML-Parser-2.*:../p5-XML-Parser
DEPENDS+=	p5-Date-Manip-*:../../devel/p5-Date-Manip

USE_PERL5=	yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/XQL/.packlist

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
