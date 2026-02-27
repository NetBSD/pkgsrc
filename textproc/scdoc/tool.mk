# $NetBSD: tool.mk,v 1.2 2026/02/27 13:24:46 kikadf Exp $
#
# This mk fragment can be included in all packages that uses `scdoc'
# as a tool.
#
# Keywords: scdoc
#

.if !defined(SCDOC_TOOL_MK)
SCDOC_TOOL_MK=	defined

TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

BUILDLINK_TARGETS+=	buildlink-bin-scdoc buildlink-pkgconfig-scdoc

.PHONY: buildlink-bin-scdoc
buildlink-bin-scdoc:
	${RUN} \
	f="${PREFIX}/bin/scdoc"; \
	d="${BUILDLINK_DIR}/bin"; \
	t="$$d/scdoc"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${MKDIR} -p $$d; \
		${LN} -sf $$f $$t; \
	fi

.PHONY: buildlink-pkgconfig-scdoc
buildlink-pkgconfig-scdoc:
	${RUN} \
	f="${PREFIX}/share/pkgconfig/scdoc.pc"; \
	d="${BUILDLINK_DIR}/share/pkgconfig"; \
	t="$$d/scdoc.pc"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${MKDIR} -p $$d; \
		${LN} -sf $$f $$t; \
	fi

.endif # SCDOC_TOOL_MK
